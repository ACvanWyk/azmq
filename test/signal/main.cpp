/*
    Copyright (c) 2013-2014 Contributors as noted in the AUTHORS file

    This file is part of azmq

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*/
#include <azmq/signal.hpp>

#include <boost/version.hpp>
#if BOOST_VERSION >= 106600
#include <boost/asio/io_context.hpp>
#else // BOOST_VERSION >= 106600
#include <boost/asio/io_service.hpp>
#endif // BOOST_VERSION >= 106600

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE( "Send/Receive a signal", "[signal]" ) {
#if BOOST_VERSION >= 106600
    boost::asio::io_context ios;
#else // BOOST_VERSION >= 106600
    boost::asio::io_service ios;
#endif // BOOST_VERSION >= 106600
    azmq::pair_socket sb(ios);
    azmq::pair_socket sc(ios);

    sb.bind("inproc://test");
    sc.connect("inproc://test");

    azmq::signal::send(sb, 123);
    REQUIRE( azmq::signal::wait(sc) == 123);
}
