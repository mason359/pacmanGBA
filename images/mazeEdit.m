img = imread('paused.png');
r = img(:,:,1);
g = img(:,:,2);
b = img(:,:,3);
mask = b < 100;
mask = cat(3, mask, mask, mask);
img(mask) = 0;
imshow(img);
imwrite(img, 'paused.png');