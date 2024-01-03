/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:47:36 by m_kamal           #+#    #+#             */
/*   Updated: 2023/12/19 13:47:36 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_replace.hpp"

ft_replace::ft_replace(const std::string &file_name, const std::string &s1,
                       const std::string &s2)
    : _filename(file_name), _search_str(s1), _replace_str(s2) {

  std::ifstream _infile(file_name.c_str());
  if (!_infile.is_open())
    throw std::string("Error: cannot open file.");

  std::string new_file = file_name + ".replace";
  _outfile.open(new_file.c_str());
  if (!_outfile.is_open()) {
    _infile.close();
    throw std::string("Error: cannot create output file.");
  }

  std::string line;
  while (std::getline(_infile, line)) {
    _replace(line);
    if (!_infile.eof())
      _outfile << std::endl;
  }

  _infile.close();
  _outfile.close();
}

ft_replace::~ft_replace(void) {}

void ft_replace::_replace(const std::string &line) {
  size_t start = 0;
  size_t found = line.find(_search_str, start);

  while (found != std::string::npos) {
    _outfile << line.substr(start, found - start) << _replace_str;
    start = found + _search_str.length();
    found = line.find(_search_str, start);
  }
  _outfile << line.substr(start, found - start);
}
