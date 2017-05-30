class Pilha
	@@pilhas_criadas = 0

	def initialize num
		@name = ''
		@store = [num] #array
		@@pilhas_criadas += 1 
	end
	#chamado quando da Pilha.new

	def last_item
		return @store.last #ultimo elemento
	end
	#metodo de instancia (cada objeto tem o seu)

	def self.pilhas_criadas #self -> para chamar metodo pela classe, não pelo objeto
		return @@pilhas_criadas
	end
	#metodo de classe (cada classe tem o msm)

	def name
		@name #metodo para retornar o nome do objeto
	end

	def name=(name)
		@name = name #metodo para colocar um nome no objeto
	end

end

