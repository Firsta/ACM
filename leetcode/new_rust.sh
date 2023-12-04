#!/usr/bin/env bash
p=$1
mkdir $p && cp -rf rust_template $p/rust && code $p/rust
