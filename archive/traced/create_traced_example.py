import torch


class MyModel(torch.nn.Module):
    """
    A simple model that takes in a tensor, performs a linear transformation,
    and returns the result.
    """
    def __init__(self):
        super(MyModel, self).__init__()
        # apply a linear transformation to the incoming data: y=Wx+b
        # self.linear = torch.nn.Linear(input_size, output_size)
        self.linear = torch.nn.Linear(1, 1)

    def forward(self, x):
        out = self.linear(x)
        return out

# this model accepts a tensor of size 1, and returns a tensor of size 1
mdl = MyModel()
# simulate a ML training process
example_weight = torch.rand(1, 1)
# example input
example_forward_input = torch.rand(1, 1)

traced_model = torch.jit.trace(mdl.forward, example_forward_input)

print(traced_model)

# save the model
traced_model.save("traced_example.pt")

# print input
print(f'input: {example_forward_input}')
# print weight
print(f'weight: {mdl.linear.weight}')
# print bias
print(f'bias: {mdl.linear.bias}')
# print output
print(f'output from tracing: {traced_model(example_forward_input)}')
print(f'output from original: {mdl.forward(example_forward_input)}')