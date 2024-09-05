report = ["rjstbhe eget kctxcoub urrmkhlmi yniqafy fkeofjpc iio yzyoatfyx khj iio","gpnhgabl qq qq fkeofjpc dflidshdb qq iio khj qq yzyoatfyx","tizpzhlbyb eget z rjstbhe iio jdh jdh iptxh qq rjstbhe","jtlghe wlinrrgcm jnkdbd k iio et rjstbhe iio qq jdh","yp fkeofjpc lkhypcebox rjstbhe ewwykishv egzhne jdh y qq qq","fu ql iio fkeofjpc jdh luspuy yzyoatfyx li qq v","wlinrrgcm iio qq omnc sgkt tzgev iio iio qq qq","d vhg qlj khj wlinrrgcm qq f jp zsmhkjokmb rjstbhe"]
positive_feedback = ["fkeofjpc","qq","iio"]
negative_feedback = ["jdh","khj","eget","rjstbhe","yzyoatfyx","wlinrrgcm"]
student_id = [96537918,589204657,765963609,613766496,43871615,189209587,239084671,908938263]
k = 3

points = [];
for i in range(0,len(student_id)):
    points.append(0);

i=0
for sentence in report:
    words = sentence.split(" ")
    for items in words:
        for pf in positive_feedback:
            if(items == pf):
                points[i]+=3;

    for items in words:
        for nf in negative_feedback:
            if(items == nf):
                points[i]-=1;

    i+=1;

print(points)
# print(points)
for i in range(len(student_id)-1):
    j=i+1;
    while(j>0):
        if(points[i] < points[j]):
            temp = points[i];
            points[i]=points[j];
            points[j]=temp;

            temp = student_id[i];
            student_id[i]=student_id[j];
            student_id[j]=temp;

        j-=1;

# return student_id;
