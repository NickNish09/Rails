dial_book = {
	"Sao Paulo" => "11",
	"Brasilia" => "61",
	"Rio Preto" => "17",
	"Rio de Janeiro" => "21",
	"Brasil" => "51"
}

loop do
	puts "Voce quer consultar novamente?(S,N)"
	resposta = gets.chomp

	if (resposta != 's' and resposta != 'S')
		break
	end




	puts "Opções:"

	dial_book.each{|k,v| puts "#{k}"}

	puts "Digite o nome da cidade a ser consultada:"
	city = gets.chomp

	def areacode (cidade,hash)
		a = hash.select{|k,v| k == cidade}
		return a[cidade];
	end

	codigo = areacode(city,dial_book)

	if dial_book.include?(city)
		puts "O codigo de #{city} é #{codigo}"
	else
		puts "Cidade nao consta no catalogo"
	end
end