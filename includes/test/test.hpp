/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:35:32 by dboyer            #+#    #+#             */
/*   Updated: 2021/05/26 11:56:08 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
#define TEST_HPP
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
template < typename test_type, typename ref_type > class Test
{
  public:
    Test< test_type, ref_type >(std::string testName, void (*f)(void (*)(test_type &, ref_type &)),
                                void (*check)(test_type &, ref_type &))
        : _testName(testName), _f(f), _check(check)
    {
    }

    Test< test_type, ref_type >(const Test &x) : _testName(x._testName), _f(x._f), _check(x._check)
    {
    }

    Test &operator=(const Test &x)
    {
        _check = x._check;
        _testName = x._testName;
        _f = x._f;
    }

    ~Test(void)
    {
    }

    bool run(void) const
    {
        try
        {
            _f(_check);
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
    void (*_f)(void (*)(test_type &, ref_type &));
    void (*_check)(test_type &, ref_type &);
};

} // namespace unittest
#endif