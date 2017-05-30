# Triangle Project Code.

# Triangle analyzes the lengths of the sides of a triangle
# (represented by a, b and c) and returns the type of triangle.
#
# It returns:
#   :equilateral  if all sides are equal
#   :isosceles    if exactly 2 sides are equal
#   :scalene      if no sides are equal
#
# The tests for this method can be found in
#   about_triangle_project.rb
# and
#   about_triangle_project_2.rb
#
def triangle(a, b, c)

  raise TriangleError if a<=0 or b<=0 or c<=0
  raise TriangleError if a+b<=c or a+c<=b or b+c<=a
  
  if a==b
  	if b==c
  		return :equilateral
  	else
  		return :isosceles
  	end
  else
  	if b==c
  		return :isosceles
  	else
  		if a==c
  			return :isosceles
  		else
  			return :scalene
  		end
  	end
  end


  

  	
  end


# Error class used in part 2.  No need to change this code.
class TriangleError < StandardError
end