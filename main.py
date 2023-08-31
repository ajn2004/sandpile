import sandpile
import numpy as np
import imageio
import matplotlib.pyplot as plt
# chat_gpt import library to help w/ image/animation saving

def makeFrame(model, iters = 1):
    model.iterate(iters)
    return model.getGrid()

def array_to_tiff_stack(array_3d, filename="output.tif"):
    # Ensure the input array is a numpy array
    array_3d = np.array(array_3d)*255/3

    # Convert the integer values to uint8 (if not already) for image representation
    # Assuming the integer values are between 0-255
    array_3d = array_3d.astype(np.uint8)

    # Save the 3D array as a TIFF stack
    imageio.mimwrite(filename, array_3d, format='TIFF')

model = sandpile.SandpileModel(240, 680)
frames = 600
skips = 10
stack = []
topples = []
model.iterate(100000)
for i in range(frames):
    # get frames and store them in array
    per = i*100/frames
    if per == np.round(per):
        print(str(per) + '% complete')
    stack.append(makeFrame(model, skips))
    topples.append(model.getTopples())
array_to_tiff_stack(stack)
# with open('output_topples', 'w+') as f:
#     f.write(str(topples))
#     f.close()

# # check power law
# powers = [0, 1, 2, 3, 4, 5,6]
# frequency = [0,0,0,0,0,0]
# for i in range(len(powers)-1):
#     for j in topples:
#         if j >= 10**powers[i] & j < 10**powers[i+1]:
#             frequency[i] += 1
# print(powers)
# print(frequency)
