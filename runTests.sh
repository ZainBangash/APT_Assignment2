# run tests and check them with git

# test
echo "run test 'test'"
diff <(./scrabble.out <"./tests/test.in") "./tests/test.expected"


echo "run test 'pass'"
diff <(./scrabble.out <"./tests/pass.in") "./tests/pass.expected"


echo "run test 'test'"
diff <(./scrabble.out <"./tests/test.in") "./tests/test.in"
