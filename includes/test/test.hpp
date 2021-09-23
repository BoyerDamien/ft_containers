/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:35:32 by dboyer            #+#    #+#             */
/*   Updated: 2021/09/20 12:00:46 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstddef>
#include <exception>
#include <iostream>

#define RED "\033[31m"   /* Red */
#define GREEN "\033[32m" /* Green */
#define WHITE "\033[37m" /* White */

namespace unittest
{
class FailedException : public std::exception
{
  public:
    const char *what(void) const throw()
    {
        return _msg.c_str();
    }
    FailedException(std::string msg) : _msg(msg)
    {
    }
    virtual ~FailedException() throw()
    {
    }

  private:
    std::string _msg;
};

template < typename test_type, typename ref_type > struct state
{
    int len;
    test_type *test_state;
    ref_type *ref_state;

    state(void) : len(0)
    {
    }

    state(int len, test_type *test_state, ref_type *ref_state) : len(len), test_state(test_state), ref_state(ref_state)
    {
    }
};

template < typename test_type, typename ref_type, typename state_type > class Test
{
  public:
    typedef void (*check_fun)(test_type &, ref_type &);
    typedef void (*fun)(check_fun, state_type);

    Test(std::string testName, fun f, check_fun check, state_type initState = state_type())
        : _testName(testName), _f(f), _check(check), _state(initState)
    {
    }

    Test(const Test &x) : _testName(x._testName), _f(x._f), _check(x._check), _state(x._state)
    {
    }

    Test &operator=(const Test &x)
    {
        _check = x._check;
        _testName = x._testName;
        _f = x._f;
        _state = x._state;
    }

    ~Test(void)
    {
    }

    bool run(void) const
    {
        try
        {
            _f(_check, _state);
            std::cout << GREEN << "Run " << _testName << " [OK]" << WHITE << std::endl;
            return true;
        }
        catch (const std::exception &e)
        {
            std::cerr << RED << "Run " << _testName << " [KO]" << WHITE << std::endl;
            std::cerr << RED << "Error: " << e.what() << WHITE << std::endl;
            return false;
        }
    }

  private:
    std::string _testName;
    fun _f;
    check_fun _check;
    state_type _state;
};

} // namespace unittest
