
puts "Digite o valor:"
a = gets.chomp.to_i
puts (1..a).to_a.select{ |x| x%2!=0}