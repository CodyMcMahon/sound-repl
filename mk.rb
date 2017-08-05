puts 'making sound_file.o'
`g++ -std=c++11 sound_file.cc -c`
puts 'making envelope.o'
`g++ -std=c++11 envelope.cc -c`
puts 'making test_core_functions.o'
`g++ -std=c++11 test_core_functions.cc -c`
puts 'making test_repl_functions.o'
`g++ -std=c++11 test_repl_functions.cc -c`
puts 'making sound_repl binary'
`g++ -std=c++11 -o sound_repl test_main.cc test_repl_functions.o test_core_functions.o sound_file.o envelope.o`
puts 'ALL DONE!'
