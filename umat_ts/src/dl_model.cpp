#include "call_ts.h"
#include <torch/script.h>
#include <iostream>
#include <memory>
#include <regex>

// c++ function invariant_nn
//
// takes inputs, reads a neural network TurbNN.pt, do a forward pass
// and returns outputs
//
// inputs: 1 tensor invariants I[0:4] (float)
// outputs: 1 tensor basis coefficients G[0:9] (float)
void dl_model(float I[], float G[])
{
    std::cout << "here\n" << std::endl;
    // deserialize scriptmodule from a .pt file
    torch::jit::script::Module module;
    std::cout << "here2\n" << std::endl;
    //const char *arg;
    std::cout << "here3\n" << std::endl;
    //arg = "/home/jferreira/umat_cpp/cube_ts/traced_example.pt";
    //std::cout << "arg:\n" << arg;
    module = torch::jit::load("/home/jferreira/umat_cpp/cube_ts/traced_example.pt");
    std::cout << "here4\n" << std::endl;
    //std::cout << "FILE:\n" << arg;
    // create inputs
    std::vector<torch::jit::IValue> inputs;
    std::cout << "here5\n" << std::endl;
    float data[] = {I[0]};
    inputs.push_back(torch::from_blob(data, {1, 1}));
    //std::cout << "inputs\n" << inputs;
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