// int i = 0;
//     double spriteX;
//     double spriteY;
//     for(; i < numSprites; i++)
//     {
//         //translate sprite position to relative to camera
//         spriteX = sprite[i].x - data->posX;
//         spriteY = sprite[i].y - data->posY;
//     }
//     sort_tex(data, /*sprite,*/ i);
//         // printf("%f %f\n", sprite[i].y, sprite[i].x);
//     for(i = 0; i < numSprites; i++)
//     {
//         double invDet = 1.0 / (data->planeX * data->dirY - data->dirX * data->planeY); //required for correct matrix multiplication
//         spriteX = (double)sprite[i].x - data->posX;
//         spriteY = sprite[i].y - data->posY;
//         double transformX = invDet * (data->dirY * spriteX - data->dirX * spriteY);
//         double transformY = invDet * (-data->planeY * spriteX + data->planeX * spriteY); //this is actually the depth inside the screen, that what Z is in 3D
//         sprite[i].distance = transformY;
//         // double invDet = 1.0 / (data->planeX * data->dirY - data->dirX * data->planeY); //required for correct matrix multiplication
//         // double transformX = invDet * (data->dirY * spriteX - data->dirX * spriteY);
//         // double transformY = invDet * (-data->planeY * spriteX + data->planeX * spriteY);
//         int spriteScreenX = (int)((screenWidth / 2) * (1 + transformX / transformY));
//         //calculate height of the sprite on screen
//         int spriteHeight = abs((int)(screenHeight / (transformY))); //using 'transformY' instead of the real distance prevents fisheye
//         //calculate lowest and highest pixel to fill in current stripe
//         int drawStartY = -spriteHeight / 2 + screenHeight / 2;
//         if(drawStartY < 0)
//             drawStartY = 0;
//         int drawEndY = spriteHeight / 2 + screenHeight / 2;
//         if(drawEndY >= screenHeight)
//             drawEndY = screenHeight - 1;
//         // printf("%f %f\n", sprite[i].y, sprite[i].x);
//         //calculate width of the sprite
//         int spriteWidth = abs((int)(screenHeight / (transformY)));
//         int drawStartX = -spriteWidth / 2 + spriteScreenX;
//         if(drawStartX < 0)
//             drawStartX = 0;
//         int drawEndX = spriteWidth / 2 + spriteScreenX;
//         if(drawEndX >= screenWidth)
//             drawEndX = screenWidth - 1;
//         //loop through every vertical stripe of the sprite on screen
//         for(int sprX = drawStartX; sprX < drawEndX; sprX++)
//         {
//             int texX = (int)(256 * (sprX - (-spriteWidth / 2 + spriteScreenX)) * texWidth / spriteWidth) / 256;
//             //the conditions in the if are:
//             //1) it's in front of camera plane so you don't see things behind you
//             //2) it's on the screen (left)
//             //3) it's on the screen (right)
//             //4) ZBuffer, with perpendicular distance
//             //double ZBuffer[screenWidth];
//             if(transformY > 0 && sprX > 0 && sprX < screenWidth && data->zBuffer[sprX] > transformY)
//                 for(int r = drawStartY; r < drawEndY; r++) //for every pixel of the crrrent sprX
//                 {
//                     int d = (r) * 256 - screenHeight * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
//                     int texY = ((d * texHeight) / spriteHeight) / 256;
//                     color = *(unsigned int*)(wall.sprit.addr + (texY * wall.sprit.line_length + texX * (wall.sprit.bits_per_pixel / 8)));
//                     if (color >> 24 == 0)
//                         my_mlx_pixel_put(data, sprX, r, color);
//                     // color = texture[sprite[spriteOrder[i]].texture][texWidth * texY + texX]; //get current color from the texture
//                     // if((color & 0x00FFFFFF) != 0) buffer[y][sprX] = color; //paint pixel if it isn't black, black is the invisible color
//                 }
//         }
//     }