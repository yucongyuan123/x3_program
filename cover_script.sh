./bin/demo_bin

gcovr -r . --html --html-details -o coverage.html
mkdir coverage
mv coverage.* coverage
