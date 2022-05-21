// Read a string out of Web Assembly memory
const readStringFromMemory = (offset, length) => {
  const stringBuffer = new Uint8Array(
    wasm.instance.exports.memory.buffer,
    offset,
    length
  );
  const decodedString = new TextDecoder().decode(stringBuffer);
  // Notify and make use of new string
  window.dispatchEvent(
    new CustomEvent("read-string-from-memory", { detail: decodedString })
  );
};

// Listen for new wasm strings
window.addEventListener("read-string-from-memory", (readString) => {
  console.log(
    "Received a new string from C programming lenguage:",
    readString.detail
  );
});

// Imports object
const imports = {
  env: {
    num_log: console.log,
    str_log: readStringFromMemory,
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
