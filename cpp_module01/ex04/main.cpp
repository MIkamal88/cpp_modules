/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:46:00 by m_kamal           #+#    #+#             */
/*   Updated: 2023/12/19 13:46:00 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_replace.hpp"

int main(int argc, char *argv[]) {
  try {
    if (argc != 4)
      throw std::runtime_error("Wrong number of arguments.");
    else
      ft_replace(std::string(argv[1]), std::string(argv[2]),
                 std::string(argv[3]));
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
		return (1);
  }
}
