/*
@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/fusion/include/at.hpp>
#include <boost/fusion/include/make_vector.hpp>
#include <boost/fusion/include/push_back.hpp>
namespace fusion = boost::fusion;


int main() {
    auto vector = <%= fusion_vector((1..input_size).map { |n| "#{n}" }) %>;
    auto result = fusion::at_c<<%= input_size-1 %>>(vector);
    (void)result;
}
