% Stanford Bunny Data taken from: 
% http://www-graphics.stanford.edu/data/3Dscanrep/

% Read data of vertices connecting each face or triangle
fid = fopen('bunny_faces.txt','r');
face_matrix = fscanf(fid,'%*f %f %f %f',[3,inf]);
face_matrix = face_matrix';
fclose(fid);

% The face data is indexed starting with 0, increment every vertex numbering by 1
[r,c] = size(face_matrix);
face_matrix = face_matrix + ones(r,c);

% Read coordinates of the vertices
fid = fopen('bunny_vertices.txt','r');
vertex_matrix = fscanf(fid,'%f %f %f %*f %*f',[3,inf]);
vertex_matrix = vertex_matrix';
fclose(fid);

% % "Center" the bunny at (0,0,0)
% translate_x = [ones(length(vertex_matrix),1),zeros(length(vertex_matrix),2)];
% translate_y = [zeros(length(vertex_matrix),1),ones(length(vertex_matrix),1),zeros(length(vertex_matrix),1)];
% translate_z = [zeros(length(vertex_matrix),2),ones(length(vertex_matrix),1)];
% 
% vertex_matrix = vertex_matrix - (max(vertex_matrix(:,1))+min(vertex_matrix(:,1)))/2*translate_x;
% vertex_matrix = vertex_matrix - (max(vertex_matrix(:,2))+min(vertex_matrix(:,2)))/2*translate_y;
% vertex_matrix = vertex_matrix - (max(vertex_matrix(:,3))+min(vertex_matrix(:,3)))/2*translate_z;

% Draw the bunny using the patch command
patch('Vertices',vertex_matrix,'Faces',face_matrix,'FaceColor','white')
axis off
axis equal

% --------------------------------------
% INSERT CODE HERE
% --------------------------------------
