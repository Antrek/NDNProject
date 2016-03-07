/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/**
 * Copyright (c) 2014  University of Memphis,
 *                     Regents of the University of California
 *
 * This file is part of NLSR (Named-data Link State Routing).
 * See AUTHORS.md for complete list of NLSR authors and contributors.
 *
 * NLSR is free software: you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * NLSR is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * NLSR, e.g., in COPYING.md file.  If not, see <http://www.gnu.org/licenses/>.
 *
 * \author Ashlesh Gawande <agawande@memphis.edu>
 *
 **/
#include "adjacency-list.hpp"
#include "adjacent.hpp"
#include <boost/test/unit_test.hpp>

namespace nlsr {

namespace test {

using namespace std;

BOOST_AUTO_TEST_SUITE(TestAdjacenctList)

BOOST_AUTO_TEST_CASE(AdjacenctListBasic)
{
  const string ADJ_NAME_1 = "testname";
  const string ADJ_NAME_2 = "testname2";

//adjacent needed to test adjacency list.
  Adjacent adjacent1(ADJ_NAME_1);
  Adjacent adjacent2(ADJ_NAME_2);

  adjacent1.setLinkCost(4);
  adjacent2.setLinkCost(5);

  AdjacencyList adjacentList1;
  AdjacencyList adjacentList2;

  adjacentList1.insert(adjacent1);
  adjacentList2.insert(adjacent2);

  BOOST_CHECK_EQUAL(adjacentList1.getSize(), (uint32_t)1);
  BOOST_CHECK_EQUAL(adjacentList1 == adjacentList2, false);

  BOOST_CHECK(adjacentList1.isNeighbor("testname"));
  BOOST_CHECK_EQUAL(adjacentList1.isNeighbor("adjacent"), false);

  string n1 = "testname";
  BOOST_CHECK_EQUAL(adjacentList1.getStatusOfNeighbor(n1), Adjacent::STATUS_INACTIVE);

  adjacentList1.setStatusOfNeighbor(n1, Adjacent::STATUS_ACTIVE);
  BOOST_CHECK_EQUAL(adjacentList1.getStatusOfNeighbor(n1), Adjacent::STATUS_ACTIVE);
}

BOOST_AUTO_TEST_SUITE_END()

} //namespace tests
} //namespace nlsr
