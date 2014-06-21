/*!
@file
Defines `boost::hana::Applicative`.

@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_APPLICATIVE_HPP
#define BOOST_HANA_APPLICATIVE_HPP

#include <boost/hana/core.hpp>
#include <boost/hana/detail/constexpr.hpp>


namespace boost { namespace hana {
    /*!
    @ingroup typeclasses
    `Applicative`s are `Functor`s with the ability to lift values and combine
    computations.

    --------------------------------------------------------------------------

    ## Minimal complete definition
    `pure` and `ap`

    --------------------------------------------------------------------------

    ## Laws
    For any `Applicative` `A`, the following laws must be satisfied:
    @code
        ap(pure<A>(id), u) == u                                  // identity
        ap(ap(ap(pure<A>(compose), u), v), w) == ap(u, ap(v, w)) // composition
        ap(pure<A>(f), pure<A>(x)) == pure<A>(f(x))              // homomorphism
        ap(u, pure<A>(y)) == ap(pure<A>(apply(y)), u)            // interchange
    @endcode

    As a consequence of these laws, the `Functor` instance for `A` will
    satisfy
    @code
        fmap(f, x) == ap(pure<A>(f), x)
    @endcode
     */
    template <typename T, typename Enable = void>
    struct Applicative;

    //! Lifted application.
    //! @method{Applicative}
    //!
    //! ### Example
    //! @snippet example/list/applicative/overview.cpp main
    //!
    //! @todo
    //! Should this be a variadic function?
    BOOST_HANA_CONSTEXPR_LAMBDA auto ap = [](auto f, auto x) {
        return Applicative<datatype_t<decltype(f)>>::ap_impl(f, x);
    };

    //! Lift a value into the functor.
    //! @method{Applicative}
    //!
    //! @todo
    //! - This is craving to be renamed to `lift`?
    //! - Remove redundancy with `Monad`'s `unit`.
    template <typename T>
    BOOST_HANA_CONSTEXPR_LAMBDA auto pure = [](auto x) {
        return Applicative<T>::pure_impl(x);
    };

    template <>
    struct instance<Applicative> {
        template <typename T, typename Enable = void>
        struct with { };
    };

    template <>
    struct defaults<Applicative> {
        template <typename T, typename Enable = void>
        struct with : defaults<> { };
    };

    template <typename T, typename Enable>
    struct Applicative : instance<Applicative>::template with<T> { };
}} // end namespace boost::hana

#endif // !BOOST_HANA_APPLICATIVE_HPP
