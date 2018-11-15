var Module = require('./wasm/BinarySearchTree')

class node{
	constructor(val){
		this.l = null;
		this.r = null;
        this.value = val;
	}
}

class Tree{
    constructor(){
        this.root = null
    }

    insert(rt,tmp){
		
		if(tmp.value < rt.value) {  
			if(rt.l === null) 
				rt.l = tmp; 
			else
				this.insert(rt.l, tmp);  
		} 
	  
		else   { 
			if(rt.r === null) 
				rt.r = tmp; 
			else
				this.insert(rt.r,tmp); 
		} 
    }
	_insert(val){
		var tmp = new node(val)
		if(this.root === null) 
			this.root = tmp; 
		else
			this.insert(this.root,tmp);
	}

    search(rt,val){
		if(rt == null) return false;
        if(rt.value == val) return true;
		if(this.search(rt.l,val) || this.search(rt.r,val)) {
			return true
		}
		
		return false;           
    }
	
	_search(val){
		if(this.search(this.root,val)) { 
			return 1;
		 }
		else { 
			return 0;
		}
	}

}

function timer(fn,ins,sea,label) {
	console.time(label);
	for(x of ins) { fn._insert(x) }
	for(x of sea) { fn._search(x) }
	console.timeEnd(label);
}

Module['onRuntimeInitialized'] = benchmark;
function benchmark(){
	var tree = new Tree();
	var arr = []
	var t = [100,1000,10000,100000]
		for (n of t){
		var values = []
		for (let i =0; i < n; i++){
			arr.push( Math.floor(Math.random()*100000) )
		}
		for (let i =0; i < n; i++){
			values.push( Math.floor(Math.random()*100000) )
		}
		timer(Module,arr,values,"WebAssembly n=" + n);
		timer(tree,arr,values,"Plain JS n=" + n);
	}
	
}
