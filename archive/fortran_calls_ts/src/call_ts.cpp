#include "call_ts.h"
#include <torch/script.h>
#include <iostream>
#include <memory>
// c++ function invariant_nn
//
// takes inputs, reads a neural network TurbNN.pt, do a forward pass
// and returns outputs
//
// inputs: 5 tensor invariants I[0:4] (float)
// outputs: 10 tensor basis coefficients G[0:9] (float)
void invariant_nn(float I[], float G[])
{
    // deserialize scriptmodule from a .pt file
    torch::jit::script::Module module;
    const char *arg;
    arg = "traced_example.pt";
    module = torch::jit::load(arg);
    std::cout << "FILE:\n" << arg;
    // create inputs
    std::vector<torch::jit::IValue> inputs;
    float data[] = {I[0]};
    inputs.push_back(torch::from_blob(data, {1, 1}));
    std::cout << "inputs\n" << inputs;
    //std::cout << "\n";

    // do forward pass and turn its output into a tensor
    at::Tensor outputs = module.forward(inputs).toTensor();
    //std::cout << "outputs\n" << outputs;
    //std::cout << "\n";

    // return values
    for (int k = 0; k < 1; k++) {
        G[k] = outputs[0][k].item().to<float>();
        //std::cout << "G\n" << G[k];
    }

    return;
}