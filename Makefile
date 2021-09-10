# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/10 16:36:02 by dboyer            #+#    #+#              #
#    Updated: 2021/09/10 11:48:35 by dboyer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#									SOURCES
################################################################################

NAME    			=	ft_containers

MAIN				= 	./srcs/main.cpp

SRCS    			= 	assert\
						test_list\
						test_vector\
						test_pair

INCLUDES			=	-I ./includes

HEADERS				=	./includes/ft_containers.hpp\
						./includes/map/map.hpp\
						./includes/map/pair.hpp\
						./includes/map/rbt_element.hpp\
						./includes/iterators/category.hpp\
						./includes/iterators/iterator_base.hpp\
						./includes/iterators/iterator_traits.hpp\
						./includes/iterators/iterator.hpp\
						./includes/iterators/map_iterator.hpp\
						./includes/iterators/reverse_iterator.hpp\
						./includes/iterators/vector_iterator.hpp\
						./includes/algorithms/algorithms.hpp\
						./includes/test/test_accessors.hpp\
						./includes/test/test_capacity.hpp\
						./includes/test/test_constructors.hpp\
						./includes/test/test_iterators.hpp\
						./includes/test/test_modifiers.hpp\
						./includes/test/test_operations.hpp\
						./includes/test/test_operators.hpp\
						./includes/test/test_utils.hpp\
						./includes/test/test_unittest.hpp\
						./includes/vector/vector.hpp


FIL					= $(addsuffix .cpp, $(addprefix ./srcs/, $(SRCS)))

OBJS				= 	$(FIL:.cpp=.o)
OBJS_MAIN			= 	$(MAIN:.cpp=.o)


CXXFLAGS  			= 	-Werror -Wall -Wextra -std=c++98 -O3 ${INCLUDES}
CXX     			= 	clang++-9
RM      			= 	rm -f

################################################################################
#								Basic Rules
################################################################################

%.o: %.cpp ${HEADERS}
	$(CXX) $(CXXFLAGS) -c $< -o $@

all     :	$(NAME)

$(NAME) :	$(OBJS) $(OBJS_MAIN)
	${CXX} ${CXXFLAGS} -o ${NAME} ${OBJS} ${OBJS_MAIN} 

clean   :
	$(RM) $(OBJS)
	$(RM) ${OBJS_MAIN}

fclean  : clean
	$(RM) $(NAME)

re      :	fclean all

################################################################################
#									Extra Rules
################################################################################
test 	:	all
	./${NAME}

.PHONY  :	all clean fclean re bonus%
