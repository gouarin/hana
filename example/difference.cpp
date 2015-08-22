/*
@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/assert.hpp>
#include <boost/hana/difference.hpp>
#include <boost/hana/integral_constant.hpp>
#include <boost/hana/set.hpp>
#include <boost/hana/type.hpp>
namespace hana = boost::hana;


constexpr auto xs = hana::make_set(hana::int_<1>, hana::int_<2>, hana::type<int>, hana::int_<3>);
constexpr auto ys = hana::make_set(hana::int_<3>, hana::type<void>, hana::type<int>);

BOOST_HANA_CONSTANT_CHECK(hana::difference(xs, ys) == hana::make_set(hana::int_<1>, hana::int_<2>));
BOOST_HANA_CONSTANT_CHECK(hana::difference(ys, xs) == hana::make_set(hana::type<void>));

int main() { }
