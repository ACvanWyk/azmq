/*
    Copyright (c) 2013-2014 Contributors as noted in the AUTHORS file

    This file is part of azmq

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*/
#ifndef AZMQ_DETAIL_SERVICE_BASE_HPP_
#define AZMQ_DETAIL_SERVICE_BASE_HPP_

#include <boost/version.hpp>
#if BOOST_VERSION >= 106600
#include <boost/asio/io_context.hpp>
#else // BOOST_VERSION >= 106600
#include <boost/asio/io_service.hpp>
#endif // BOOST_VERSION >= 106600

namespace azmq {
namespace detail {
    template <typename T>
    class service_id
        : public
#if BOOST_VERSION >= 106600
		  boost::asio::io_context::id
#else // BOOST_VERSION >= 106600
		  boost::asio::io_service::id
#endif // BOOST_VERSION >= 106600

    { };

    template<typename T>
    class service_base
        : public
#if BOOST_VERSION >= 106600
		  boost::asio::io_context::service
#else // BOOST_VERSION >= 106600
		  boost::asio::io_service::service
#endif // BOOST_VERSION >= 106600
         {
    public :
        static azmq::detail::service_id<T> id;

		// Constructor.
#if BOOST_VERSION >= 106600
		    service_base(boost::asio::io_context& io_service) :
			    boost::asio::io_context::service(io_service)
		    {
		    }
#else // BOOST_VERSION >= 106600
		    service_base(boost::asio::io_service& io_service) :
			    boost::asio::io_service::service(io_service)
		    {
		    }
#endif // BOOST_VERSION >= 106600
    };

    template <typename T>
    azmq::detail::service_id<T> service_base<T>::id;
} // namespace detail
} // namespace azmq
#endif // AZMQ_DETAIL_SERVICE_BASE_HPP_

