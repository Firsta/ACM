idx := $(shell basename $(shell dirname ${PWD}))

push:
	git add ./ && git commit -m "leetcode ${idx} in rust" && git push

run:
	cargo fmt && cargo run
