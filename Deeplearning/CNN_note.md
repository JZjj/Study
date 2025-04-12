## Convolutional Neural Network 
https://poloclub.github.io/cnn-explainer/

A CNN is a neural network: recognize patterns in data. NNs are composed of collection of neurons that are organized in layers,
with own learnable weights and biases.

In CNN, the kernel (or filter) slides over the input image (or feature map), computing a dot product between the filter weights and 
the overlapping patch of the input. This results in a single number per location.

### Understanding hyperparameter
Padding is often necessary when the kernel extends beyond the activation map. 
Padding conserves data at the borders of activation maps, which leads to better performance, and it can help preserve the input's spatial size, which allows an architecture designer to build deeper, higher performing networks. There exist many padding techniques, but the most commonly used approach is zero-padding because of its performance, simplicity, and computational efficiency. The technique involves adding zeros symmetrically around the edges of an input. 

This approach is adopted by many high-performing CNNs such as AlexNet. Kernel size, often also referred to as filter size, refers to the dimensions of the sliding window over the input. Choosing this hyperparameter has a massive impact on the image classification task. For example, small kernel sizes are able to extract a much larger amount of information containing highly local features from the input. As you can see on the visualization above, 
a smaller kernel size also leads to a smaller reduction in layer dimensions, which allows for a deeper architecture. Conversely,
a large kernel size extracts less information, which leads to a faster reduction in layer dimensions, often leading to worse performance. Large kernels are better suited to extract features that are larger. At the end of the day, choosing an appropriate kernel size will be dependent on your task and dataset, but generally, smaller kernel sizes lead to better performance for the image classification task because an architecture designer is able to stack 
more and more layers together to learn more and more complex features!

Stride indicates how many pixels the kernel should be shifted over at a time. For example, as described in the convolutional layer example above, Tiny VGG uses a stride of 1 for its convolutional layers, which means that the dot product is performed on a 3x3 window of the input to yield an output value, then is shifted to the right by one pixel for every subsequent operation. The impact stride has on a CNN is similar to kernel size. As stride is decreased, more features are learned because more data is extracted, which also
leads to larger output layers. On the contrary, as stride is increased, this leads to more limited feature extraction and smaller output layer dimensions. One responsibility of the architecture designer is to ensure that the kernel slides across the input symmetrically when implementing a CNN. Use the hyperparameter visualization above to alter stride on various input/kernel dimensions to understand this constraint!
