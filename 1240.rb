#!/usr/bin/env ruby

result = {'true'=> 'encaixa', 'false'=> 'nao encaixa'}
gets.to_i.times {
    a, b = gets.split
    puts "#{result[a.end_with?(b).to_s]}"
}
