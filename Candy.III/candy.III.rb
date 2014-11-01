test_case = gets.chomp
sum = 0;

el_gancho = gets

test_case.to_i.times do 
  input = gets.chomp
  
   input.to_i.times do 
    sum += gets.chomp.to_i
  end
  
  sum % input.to_i == 0 ? puts("YES") : puts("NO")
  sum = 0
  
  el_gancho = gets

end
