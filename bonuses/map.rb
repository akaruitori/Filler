# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    map.rb                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/16 16:06:08 by dtimeon           #+#    #+#              #
#    Updated: 2019/09/16 19:17:26 by dtimeon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

require_relative 'pos'

class Map
	attr_reader :rows, :columns, :map_content

	def initialize
		@rows = rand(10..100)
		@columns = rand(10..100)
		@player1_pos = Pos.new(@rows - 1, @columns - 1)
		@player2_pos = Pos.new(@rows - 1, @columns - 1)
		while (@player1_pos.x == @player2_pos.x && @player1_pos.y == @player2_pos.y)
			@player2_pos = Pos.new(@rows, @columns)
		end
		make_map
		@file = File.new("random_map", "w+")
		@file.puts @map_content
		@file.close
	end
	
	def make_map
		@map_content = []
		(@rows).times { |row| @map_content[row] = "" }
		(0...@rows).each do |row|
			@map_content[row] << ('.' * @columns)
			@map_content[row] << ("\n")
		end
		@map_content[@player1_pos.y][@player1_pos.x] = 'O'
		@map_content[@player2_pos.y][@player2_pos.x] = 'X'
	end

	def filename
		@file.path
	end
end
