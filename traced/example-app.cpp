#include <torch/script.h> // One-stop header.

#include <iostream>
#include <memory>

int main(int argc, const char *argv[]) {
  // if (argc != 2) {
  //   std::cerr << "usage: example-app <path-to-exported-script-module>\n";
  //   return -1;
  // }

  torch::jit::script::Module module;
  try {
    // Deserialize the ScriptModule from a file using torch::jit::load().
    // module = torch::jit::load(argv[1]);
    module = torch::jit::load("traced_model.pt");
  } catch (const c10::Error &e) {
    std::cerr << "error loading the model\n";
    return -1;
  }

  std::cout << "ok\n";

  // Create a vector of inputs.
  std::vector<torch::jit::IValue> inputs;
  inputs.push_back(torch::ones({1, 1}));

  // Execute the model and turn its output into a tensor.
  at::Tensor output = module.forward(inputs).toTensor();
  std::cout << "stresses\n";
  std::cout << output.slice(/*dim=*/1, /*start=*/0, /*end=*/1) << '\n';

  std::cout << "sum of stresses\n";
  std::cout << sum(output) << std::endl;
}