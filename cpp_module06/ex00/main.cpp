/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:08:56 by m_kamal           #+#    #+#             */
/*   Updated: 2024/05/21 20:08:56 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << RED << "Error: Usage ./convert ..." << RESET << std::endl;
		return EXIT_FAILURE;
	}
	Converter::convert(argv[1]);
}
