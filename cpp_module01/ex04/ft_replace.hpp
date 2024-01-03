/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:47:41 by m_kamal           #+#    #+#             */
/*   Updated: 2023/12/19 13:47:41 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REPLACE_HPP

#define FT_REPLACE_HPP

#include <fstream>
#include <iostream>
#include <string>

class ft_replace {
private:
  std::string _filename;
  std::string _search_str;
  std::string _replace_str;
  std::ofstream _outfile;
	void	_replace(const std::string &line);

public:
  ft_replace(const std::string &filename, const std::string &s1, const std::string &s2);
  ~ft_replace(void);
};

#endif
