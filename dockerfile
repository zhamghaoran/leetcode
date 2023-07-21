FROM openjdk:11
WORKDIR /app
COPY RongXiaoTong-1.0-SNAPSHOT.jar /app
ENTRYPOINT ["java","-jar","RongXiaoTong-1.0-SNAPSHOT.jar"]