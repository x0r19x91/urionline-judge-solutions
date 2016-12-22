#!/usr/bin/env ruby

loop do
    string = gets
    break if string == nil
    n, m = string.split.map(&:to_i)
    puts "#{(m-n).abs}"
end
