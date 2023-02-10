import os

import pytest
import torch
import logging
#import nn.Module here: 
from src.models import TransferModel

MODEL = "path/to/model.bin"
OUT_FEATURES = 6


x = [torch.rand(1, 9)]


@pytest.fixture()
def trained_model():
    model = TransferModel(OUT_FEATURES)
    model.load_state_dict(torch.load(MODEL))
    # set model to eval mode for inference
    model.eval()
    return model


@pytest.fixture()
def trace_model(tmp_path, trained_model):
    """
    Trace the transfer_model (nn.Module) using torchscript.
    steps:
    - load the trained model MODEL_DIR
    - trace model
    useful links:
    - https://pytorch.org/tutorials/beginner/Intro_to_TorchScript_tutorial.html
    - https://pytorch.org/tutorials/advanced/cpp_export.html
    - https://pytorch.org/tutorials/recipes/torchscript_inference.html
    - https://torchtutorialstaging.z5.web.core.windows.net/beginner/vt_tutorial.html (for vision transformers)
    """
    # random input of size 1x6
    x = torch.rand(1, 6)
    logging.info("testing with random input x of size 1x9  ...\n")
    logging.info(f"model: {trained_model}\n")
    logging.info(f"forward pass on the input x : {trained_model.forward(x)}\n")
    logging.info(f"Returns a tensor of size 1x{OUT_FEATURES}\n")
    logging.info(f"Model has {OUT_FEATURES} features\n")

    logging.info("Tracing the model...")
    # trace the model
    traced_model = torch.jit.trace(trained_model, (x))
    # graph traced model
    logging.info(traced_model.graph)
    # code traced model
    logging.info(traced_model.code)
    # save the traced model
    traced_model.save(os.path.join(tmp_path, "traced_model.pt"))

    return traced_model


@pytest.mark.parametrize("x", x)
def test_trace_model(trace_model, trained_model, x):
    logging.info("traced_model.forward(x) == trained_model.forward(x)?\n")
    assert torch.all(trace_model.forward(x) == trained_model.forward(x))