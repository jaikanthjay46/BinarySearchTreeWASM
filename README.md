# BinarySearchTree WASM
A repo aimed at experimenting with WASM using BST,

# Usage
- clone this repo using `git clone https://github.com/jaikanthjay46/BinarySearchTreeWASM.git`
- `npm run benchmark` to run the benchmark

## About the benchmark
 - The bechmark generates random numbers to insert and search the BST, 
 - The  wasm folder contains wasm code and its JS loader.
 - a PlainJS implementation of BST is available in `benchmark.js` file
 - both the implementations are tested against the generated data.
 
 ### Results
 
N  |100|1000|10000|100000
:-----:|:-----:|:-----:|:-----:|:-----:
**WASM**|0.472ms|3.207ms|34.291ms|290.082ms
**Plain JS**|5.784ms|35.414ms|5259.039ms|693171.489ms

The WASM implementation respects the time-complexity of BST which is nlogn at worst, contrary to that the JS Implementation grows exponentially.


