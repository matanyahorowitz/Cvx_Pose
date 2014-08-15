function [sub_model] = subsample_pc(pc, subsample)

n = size(pc,2);
nn = floor(n/subsample);
sub_model = zeros(3,nn);

count = 1;
for i=1:n
    if mod(i,subsample) == 0
        sub_model(:,count) = pc(:,i);
        count = count + 1;
    end
end

end