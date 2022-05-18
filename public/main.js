// Imports object
const imports = {
  env: {
    num_log: console.log,
    str_log: console.log,
  },
};

// Load WASM
WebAssembly.instantiateStreaming(fetch("/program.wasm"), imports).then(
  (wasm) => {
    console.log("WASM Ready.");
    // Make the wasm object accessible
    window.wasm = wasm;
    
    // Log out all the exported functions
    console.log(WebAssembly.Module.exports(wasm.module));
    // Log out all the imported functions
    console.log(WebAssembly.Module.imports(wasm.module));

    // Call get_double_number() function
    wasm.instance.exports.get_double_number(100);
    // Call greet() function
    wasm.instance.exports.greet();
  }
);
