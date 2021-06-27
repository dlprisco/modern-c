// Literals of various temperature scales

/*

    To meet this requirement, we need to provide an implementation for several types,
 operators, and functions:
 
        * An enumeration of supported temperature scales called scale.
 
        * A class template to represent a temperature value, parameterized with the scale,
        called quantity.

        * Comparison operators ==, !=, <, >, <=, and >= that compare two quantities of the
        same time.

        * Arithmetic operators + and - that add and subtract values of the same quantity
        type. Additionally, we could implement member operators += and -+.

        * A function template to convert temperatures from one scale to another, called
        temperature_cast. This function does not perform the conversion itself but uses type traits to do that.

        * Literal operators ""_deg, ""_f, and ""_k for creating user-defined temperature
        literals.

*/
using namespace std;

bool are_equal(double const d1, double const d2, double const epsilon = 0.001) {
    return fabs(d1 - d2) < epsilon;
}


namespace temperature {
    enum class scale { celsius, fahrenheit, kelvin };
    template <scale S>
    
    class quantity {
        const double amount;
    public:
        constexpr explicit quantity(double const a) : amount(a) {}

        explicit operator double() const {
            return amount; 
        }
    };
}

namespace temperature {

    template <scale S>
    inline bool operator==(quantity<S> const & lhs, quantity<S> const & rhs) {
        return are_equal(static_cast<double>(lhs), static_cast<double>(rhs));
    }

    template <scale S>
    inline bool operator!=(quantity<S> const & lhs, quantity<S> const & rhs) {
        return !(lhs == rhs);
    }

    template <scale S>
    inline bool operator< (quantity<S> const & lhs, quantity<S> const & rhs) {
        return static_cast<double>(lhs) < static_cast<double>(rhs);
    }

    template <scale S>
    inline bool operator> (quantity<S> const & lhs, quantity<S> const & rhs) {
        return rhs < lhs;
    }

    template <scale S>
    inline bool operator<=(quantity<S> const & lhs, quantity<S> const & rhs) {
        return !(lhs > rhs);
    }

    template <scale S>
    inline bool operator>=(quantity<S> const & lhs, quantity<S> const & rhs) {
        return !(lhs < rhs);
    }

    template <scale S>
    constexpr quantity<S> operator+(quantity<S> const &q1, quantity<S> const &q2) {
        return quantity<S>(static_cast<double>(q1) + static_cast<double>(q2));
    }

    template <scale S>
    constexpr quantity<S> operator-(quantity<S> const &q1, quantity<S> const &q2) {
        return quantity<S>(static_cast<double>(q1) -static_cast<double>(q2));
    }
}    


namespace temperature {
    template <scale S, scale R>
    struct conversion_traits {
        static double convert(double const value) = delete;
    };

    template <>
    struct conversion_traits<scale::celsius, scale::fahrenheit> {
        static double convert(double const value) {
            return (value * 9) / 5 + 32;
        }
    };

    template <>
    struct conversion_traits<scale::fahrenheit, scale::celsius> {
        static double convert(double const value) {
            return (value - 32) * 5 / 9;
        }
    };

    template <scale R, scale S>
    constexpr quantity<R> temperature_cast(quantity<S> const q) {
        return quantity<R>(conversion_traits<S, R>::convert(static_cast<double>(q)));
    }
}