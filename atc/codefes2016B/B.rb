n, a, b = gets.split.map(&:to_i)
na = 0
nb = 0
gets.chomp.each_char{|c|
  if case c
  when "a"
    if na + nb < a + b
      na += 1
      true
    else false end
  when "b"
    if na + nb < a + b && nb < b
      nb += 1
      true
    else false end
  else
    false
  end then
    puts "Yes"
  else
    puts "No"
  end
}
