# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    config.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mykman <mykman@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/06 00:12:33 by mykman            #+#    #+#              #
#    Updated: 2022/08/07 18:28:53 by mykman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh

if [ ! -d Libft ]
then
	git clone https://github.com/Alienxbe/Libft Libft
else
	git -C Libft pull
fi
