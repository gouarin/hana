/*!
@file
Defines `boost::hana::union`.

@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_UNION_HPP
#define BOOST_HANA_UNION_HPP

#include <boost/hana/fwd/union.hpp>

#include <boost/hana/core/datatype.hpp>
#include <boost/hana/core/default.hpp>
#include <boost/hana/core/models.hpp>
#include <boost/hana/core/when.hpp>
#include <boost/hana/detail/dispatch_if.hpp>


namespace boost { namespace hana {
    //! @cond
    template <typename Xs, typename Ys>
    constexpr auto union_t::operator()(Xs&& xs, Ys&& ys) const {
        using S = typename datatype<Xs>::type;
        using Union = BOOST_HANA_DISPATCH_IF(union_impl<S>,
            true
        );

        return Union::apply(static_cast<Xs&&>(xs), static_cast<Ys&&>(ys));
    }
    //! @endcond

    template <typename S, bool condition>
    struct union_impl<S, when<condition>> : default_ {
        template <typename ...Args>
        static constexpr auto apply(Args&& ...) = delete;
    };
}} // end namespace boost::hana

#endif // !BOOST_HANA_UNION_HPP
