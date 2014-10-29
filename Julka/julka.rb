def klaudia_and_natalia_apples total_apples, klaudia_extra_apples
  klaudia_apples = (total_apples).to_i - ((total_apples.to_i - klaudia_extra_apples.to_i)/2)
  natalia_apples = (total_apples.to_i - klaudia_extra_apples.to_i)/2

  return klaudia_apples,natalia_apples
end


10.times do
  total_of_apples = gets.chomp
  klaudia_extra_apples = gets.chomp
  puts klaudia_and_natalia_apples(total_of_apples, klaudia_extra_apples)
end
