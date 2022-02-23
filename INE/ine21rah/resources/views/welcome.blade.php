@extends('templates.master')

    <!-- CENTRAL CONTENT --> 
    @section('content-center')
    <?php $iCont = 0; $iNumRow = 1;?>
    @foreach ($aProduct_offering as $product)
    
    <?php if($iCont > 3):?>
        <div class="row">
        <?php $iCont=0; $iNumRow++;
        else: $iCont++; ?>
    <?php endif; ?>

        <div class="col-sm-3">
        <div class="card border-0">
            <div class="product-image">
                <a href="/product/{{$product->id}}">
                    <img class="pic-1" style="max-width:100%;" src= {{ $product->imgurl}}>
                </a>
            </div>
            <div class="product-content">
                <h3 class="title"><a>{{ $product->name }} </a></h3>
                    <div class="price"> 
                    <h5 class="title"><a>{{ $product->price - $product->price*($product->discountPercent/100) }} €</a></h5>
                        <p><small><del>{{ $product->price }} €</del> - {{$product->discountPercent}}% de descuento</small></p>
                    </div>
            </div>
        </div>
    </div>
    <?php if($iNumRow > 0 && $iCont == 0):?>
        </div>
    <?php endif; ?>

   @endforeach
    <h3 class="h3">Nuevos productos</h3>
    <?php $iCont2 = 0; $iNumRow2 = 1;?>
    @foreach ($aProduct_new as $product)
     <?php if($iCont2 > 3):?>
        <div class="row">
        <?php $iCont2=0; $iNumRow2++;
        else: $iCont2++; ?>
    <?php endif; ?>
    @if( $product->HasDiscount()== true)
    <div class="col-sm-3">
        <div class="card border-0">
            <div class="product-image">
                <a href="#">
                    <img class="pic-1" style="max-width:100%;" src= {{ $product->imgurl}}>
                </a>
            </div>
            <div class="product-content">
                <h3 class="title"><a>{{ $product->name }} </a></h3>
                    <div class="price"> 
                    <h5 class="title"><a>{{ $product->price - $product->price*($product->discountPercent/100) }} €</a></h5>
                        <p><small><del>{{ $product->price }} €</del> - {{$product->discountPercent}}% de descuento</small></p>
                    </div>
            </div>
        </div>
    </div>
    
    @else
    <div class="col-sm-3">
        <div class="card border-0">
            <div class="product-image">
                <a href="#">
                    <img class="pic-1" style="max-width:100%;" src= {{ $product->imgurl}}>
                </a>
            </div>
            <div class="product-content">
                <h3 class="title"><a>{{ $product->name }} </a></h3>
                    <div class="price"> 
                    <h5 class="title"><a>{{ $product->price }} €</a></h5>
                    </div>
            </div>
        </div>
    </div>
    @endif
    <?php if($iNumRow2 > 0 && $iCont2 == 0):?>
        </div>
    <?php endif; ?>
    @endforeach
    @endsection

    <!-- RIGHT CONTENT --> 
    @section('content-right')
           
        <div class="col-sm-8 mx-auto">
            <div class="card border-0">
                <div class="product-image">
                    <a href="#">
                        <img class="img-responsive" style="max-width:80%;" src="Imagenes/juegoconsola.png">
                    </a>
                </div>
                <div class="product-content">
                    <h6 class="title"><a>60.00€</a></h6>
                </div>
            </div>
        </div> 
        <div class="col-sm-8 mx-auto">
            <div class="card border-0">
                <div class="product-image">
                    <a href="#">
                        <img class="img-responsive" style="max-width:80%;" src="Imagenes/juegoconsola.png">
                    </a>
                </div>
                <div class="product-content">
                    <h6 class="title"><a>60.00€</a></h6>
                </div>
            </div>
        </div>
        <div class="col-sm-8 mx-auto">
            <div class="card border-0">
                <div class="product-image">
                    <a href="#">
                        <img class="img-responsive" style="max-width:80%;" src="Imagenes/juegoconsola.png">
                    </a>
                </div>
                <div class="product-content">
                    <h6 class="title"><a>60.00€</a></h6>
                </div>
            </div>
        </div>
        <div class="col-sm-8 mx-auto">
            <div class="card border-0">
                <div class="product-image">
                    <a href="#">
                        <img class="img-responsive" style="max-width:80%;" src="Imagenes/juegoconsola.png">
                    </a>
                </div>
                <div class="product-content">
                    <h6 class="title"><a>60.00€</a></h6>
                </div>
            </div>
        </div>
    @endsection