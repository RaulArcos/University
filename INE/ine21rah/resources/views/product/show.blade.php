@include('layouts.header')
<html>
    <head>
        <link href="{{asset('css/producto.css')}}" rel="stylesheet" />
    </head>

    <body>
        <div class="card card-body">
            <section class="tm-mb-1" id="about">
                <div class="tm-row tm-about-row">
                    <div class="tm-section-1-l">
                        <img src="{{$product->imgurl}}" alt="About image" class="tm-img-responsive">
                    </div>
                    <article class="tm-section-1-r tm-bg-color-8">
                        <h2 class="tm-mb-2 tm-title-color">{{$product->name}}</h2>
                        <p>{{$product->description}}</p>
                        <p>Precio anterior: {{$product->price}}$</p>
                        <p>¡ Aproveche la oferta del {{$product->discountPercent*100}}% y cómprelo solamente por:{{$product->price*$product->discountPercent}}$ !</p>
                        <a href="#Comprar" class="tm-btn tm-btn-3 ">Comprar</a>
                        <a href="/" class="tm-btn tm-btn-1 ">Volver Atrás</a>
                    </article>
                </div>
            </section>
        </div>
    </body>
</html>   
@include('layouts.footer')
    
