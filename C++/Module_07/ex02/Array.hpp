/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:26:17 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/06 18:23:40 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
	public:
				Array(void) : _size(0) {}
				Array(size_t size) : _array(new T[size]), _size(size) {}
				Array(Array const &to_copy) :_array(new T[to_copy._size]), _size(to_copy._size)
				{
					for (size_t i = 0; i < this->_size; ++i)
						this->_array[i] = to_copy._array[i];
				}
				~Array(void) { delete this->_array; }
		Array	&operator=(Array const &to_copy)
		{
			if (this == &to_copy)
				return (*this);
			delete this->_array;
			this->_array = new T[to_copy._size];
			for (size_t i = 0; i < this->_size; ++i)
				this->_array[i] = to_copy._array[i];
			return (*this);
		}
		T		&operator[](size_t index) const
		{
			if (index >= this->_size)
				throw OutOfRange();
			return (this->_array[index]);
		}
		size_t	getSize(void) const
		{
			return (this->_size);
		}
		class	OutOfRange : public std::exception
		{
			public:
				const char	*what(void) const throw()
				{
					return ("Index bigger than the size of the array");
				}
		};

	private:
		T		*_array;
		size_t	_size;
};

template <typename T>
std::ostream	&operator<<(std::ostream &out, Array<T> const &array)
{
	for (size_t i = 0; i < array.getSize(); ++i)
	{
		if (sizeof(array[0]) == sizeof(char))
			out << array[i];
		else
			out << array[i] << " ";
	}
	return (out);
}

#endif
