
def distancia
	puts "Digite o valor de x1,x2,y1,y2:"
	x1 = gets.chomp.to_i
	
	y1 = gets.chomp.to_i

	x2 = gets.chomp.to_i

	y2 = gets.chomp.to_i

	dist = Math.sqrt((((x2-x1)**2)+((y2-y1)**2)))
	puts (dist.to_s)
end

distancia
