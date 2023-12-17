import {NestFactory} from '@nestjs/core';
import {AppModule} from './app.module';
import {SwaggerModule, DocumentBuilder} from '@nestjs/swagger'

async function bootstrap() {
    const app = await NestFactory.create(AppModule);
    const config = new DocumentBuilder()
        .setTitle('Project C')
        .setDescription('The project C API for user position')
        .setVersion('1.0')
        .addTag('projectC')
        .build();
    const document = SwaggerModule.createDocument(app, config);
    SwaggerModule.setup('api', app, document);
    await app.listen(8000);
}

bootstrap();
