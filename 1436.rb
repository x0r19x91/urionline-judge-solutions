#!/usr/bin/env ruby

gets.to_i.times do |i|
    n, *arr = gets.split.map(&:to_i)
    arr.sort!
    puts "Case #{i+1}: #{arr[n >> 1]}"
end
