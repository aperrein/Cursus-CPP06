/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:09:31 by aperrein          #+#    #+#             */
/*   Updated: 2023/10/30 09:09:33 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int             is_int(std::string s)
{
    int i = 0;
    if (s[i] == '-')
        i++;
    while (s[i])
    {
        if (!isdigit(s[i]))
            return (0);
        i++;
    }
    return (1);
}

int             is_float(std::string s)
{
    int c = 0;
    int i = 0;
    char    *end;
    double  test = 0;
    if (s[i] == '-')
        i++;
    while (s[i])
    {
        if (!isdigit(s[i]) && s[i] != '.' && s[i] != 'f')
            return (0);
        if (s[i] == '.' || s[i] == 'f')
            c++;
        i++;
    }
    if (s[i-1] != 'f' || c != 2 || i > 42)
        return (0);
    if (!isdigit(s[i-2]))
        return (0);
    test = strtod(s.c_str(), &end);
    if (test > std::numeric_limits<float>::max() || test < -std::numeric_limits<int>::max())
        return (0);
    return (1);
}

int             is_double(std::string s)
{
    int i = 0;
    int c = 0;
    if (s[i] == '-')
        i++;
    while (s[i])
    {
        if (!isdigit(s[i]) && s[i] != '.')
            return (0);
        if (s[i] == '.')
            c++;
        i++;
    }
    if (!isdigit(s[i-1]) || c != 1 || i > 310)
        return (0);
    return (1);
}

void                ScalarConverter::convert(std::string s)
{
    char            r_c = 0;
    int             r_i = 0;
    float           r_f = 0;
    double          r_d = 0;
    std::stringstream   cc;
    std::stringstream   ii;
    std::stringstream   ss;
    std::stringstream   ff;
    std::string     char_r = "Non displayable";
    std::string     int_r = "impossible";
    std::string     float_r = "impossible";
    std::string     double_r;
    char        *end;

    if (s.empty())
        throw ScalarConverter::ImpossibleConvertion();
    if (s.size() == 1 && !isdigit(s[0]))
    {
        r_c = static_cast<char>(s[0]);
        char_r = r_c;
        r_i = static_cast<int>(s[0]);
        ss << r_i;
        ss >> int_r;
        float_r = int_r + ".0f";
        double_r = int_r + ".0";   
    }
    else if (isdigit(s[0]) || (s[0] == '-' && isdigit(s[1])))
    {
        if (is_int(s))
        {
            r_d = strtod(s.c_str(), &end);
            if (r_d > std::numeric_limits<int>::max() || r_d < std::numeric_limits<int>::min())
                throw ScalarConverter::ImpossibleConvertion();
            r_i = atoi(s.c_str());
            if (r_i < 0 || r_i > 127)
                char_r = "impossible";
            else if (!(r_i < 32 || r_i >= 127))
            {
                r_c = static_cast<char>(r_i);
                cc << "'" << r_c << "'";
                cc >> char_r;
            }
            int_r = s;
            float_r = int_r + ".0f";
            double_r = int_r + ".0"; 
        }
        else if (is_float(s))
        {   
            r_f = strtof(s.c_str(), &end);
            if (!(r_f > std::numeric_limits<int>::max() || r_f < std::numeric_limits<int>::min()))
            {
                r_i = static_cast<int>(r_f);
                ii << r_i;
                ii >> int_r;
                if (!(r_i < 32 || r_i >= 127))
                {
                    r_c = static_cast<char>(r_f);
                    cc << "'" << r_c << "'";
                    cc >> char_r;
                }
                else if (r_i < 0 || r_i > 127)
                    char_r = "impossible";
            }
            float_r = s;
            double_r = s.substr(0, s.size() - 1);
            //std::cout << "is float\n";
        }
        else if (is_double(s))
        {
            r_d = strtod(s.c_str(), &end);
            if (!(r_d > std::numeric_limits<int>::max() || r_d < std::numeric_limits<int>::min()))
            {
                r_i = static_cast<int>(r_d);
                ii << r_i;
                ii >> int_r;
                if (!(r_i < 32 || r_i >= 127))
                {
                    r_c = static_cast<char>(r_d);
                    cc << "'" << r_c << "'";
                    cc >> char_r;
                }
                else if (r_i < 0 || r_i > 127)
                    char_r = "impossible";
            }
            if (!(r_d > std::numeric_limits<float>::max() || r_d < -std::numeric_limits<float>::max()))
            {
                if (s.size() > 42)
                {
                    r_f = static_cast<float>(r_d);
                    ff << r_f << "f";
		            ff >> float_r;
                }
                else
                    float_r = s + "f";
            }
            double_r = s;
            //std::cout << "is double\n";
        }
        else
            throw ScalarConverter::ImpossibleConvertion();
        
    }
    else if (s == "-inff" || s == "+inff" || s == "nanf" || s == "-inf" || s == "+inf" || s == "nan")
    {
        if (s[0] == '+')
        {
			ss << s[0];
            ff << s[0];
        }
		r_d = strtod(s.c_str(), &end);
		r_f = static_cast<float>(r_d);

		ss << r_d;
		ss >> double_r;

		ff << r_f << "f";
		ff >> float_r;
        char_r = "impossible";
    }
    else
        throw ScalarConverter::ImpossibleConvertion();
    
    std::cout << "char: " << char_r << std::endl;
    std::cout << "int: " << int_r << std::endl;
    std::cout << "float: " << float_r << std::endl;
    std::cout << "double: " << double_r << std::endl;
    //std::cout << std::numeric_limits<float>::max() << "   |    " << std::numeric_limits<double>::max();
}

const char*         ScalarConverter::ImpossibleConvertion::what() const throw()
{
    return ("Impossible convertion");
}
