/*
@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/tuple.hpp>


int main() {
    constexpr auto tuple = boost::hana::tuple_c<int,
        <%= (1..input_size).map { |n| "#{n}" }.join(', ') %>
    >;
    (void)tuple;
}
